#include "PluginEditor.h"

ChendaEditor::ChendaEditor(ChendaProcessor& p)
    : AudioProcessorEditor(&p), processor(p)
{
    setSize(400, 200);
}

ChendaEditor::~ChendaEditor() {}

void ChendaEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::darkgrey);
    g.setColour(juce::Colours::white);
    g.setFont(24.0f);
    g.drawFittedText("Chenda", getLocalBounds(), juce::Justification::centred, 1);
}

void ChendaEditor::resized() {}
