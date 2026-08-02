#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class ChendaEditor : public juce::AudioProcessorEditor
{
public:
    ChendaEditor(ChendaProcessor&);
    ~ChendaEditor() override;
    void paint(juce::Graphics&) override;
    void resized() override;

private:
    ChendaProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ChendaEditor)
};