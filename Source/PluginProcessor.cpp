#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <BinaryData.h>

ChendaProcessor::ChendaProcessor()
    : AudioProcessor(BusesProperties()
        .withOutput("Output", juce::AudioChannelSet::stereo(), true))
{
    formatManager.registerBasicFormats();  // registers WAV, AIFF support
    loadSample();
}

ChendaProcessor::~ChendaProcessor() {}

void ChendaProcessor::loadSample()
{
    // Load the embedded WAV from BinaryData
    juce::MemoryInputStream* mis = new juce::MemoryInputStream(
        BinaryData::kick_wav,
        BinaryData::kick_wavSize,
        false  // don't copy — BinaryData owns the memory
    );

    juce::AudioFormatReader* reader =
        formatManager.createReaderFor(std::unique_ptr<juce::InputStream>(mis));

    if (reader == nullptr)
    {
        // If this fires, the WAV file wasn't embedded correctly —
        // check CMakeLists.txt and rebuild
        jassertfalse;
        return;
    }

    // This sound will respond to all MIDI notes (0-127) on all channels
    juce::BigInteger allNotes;
    allNotes.setRange(0, 128, true);

    synth.addSound(new juce::SamplerSound(
        "kick",          // name
        *reader,         // audio data
        allNotes,        // MIDI note range
        60,              // root note (middle C) — sample plays at original pitch
        0.001,           // attack (seconds)
        0.1,             // release (seconds)
        10.0             // max sample length (seconds)
    ));

    synth.addVoice(new juce::SamplerVoice());
    synth.addVoice(new juce::SamplerVoice());
    synth.addVoice(new juce::SamplerVoice());
    synth.addVoice(new juce::SamplerVoice());

    delete reader;
}

void ChendaProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    synth.setCurrentPlaybackSampleRate(sampleRate);
    juce::ignoreUnused(samplesPerBlock);
}

void ChendaProcessor::releaseResources() {}

void ChendaProcessor::processBlock(juce::AudioBuffer<float>& buffer,
                                   juce::MidiBuffer& midiMessages)
{
    buffer.clear();
    synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

juce::AudioProcessorEditor* ChendaProcessor::createEditor()
{
    return new ChendaEditor(*this);
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ChendaProcessor();
}