cmake_minimum_required(VERSION 3.22)
project(ChendaPlugin VERSION 0.1.0)

add_subdirectory(C:/JUCE JUCE)

juce_add_plugin(ChendaPlugin

    COMPANY_NAME "Arjun"
    IS_SYNTH TRUE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    PLUGIN_MANUFACTURER_CODE Mfr1
    PLUGIN_CODE Chnd
    FORMATS VST3 Standalone
    PRODUCT_NAME "Chenda"
    VST3_CAN_REPLACE_VST2 FALSE
)

target_sources(ChendaPlugin PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
)

target_compile_features(ChendaPlugin PRIVATE cxx_std_17)

juce_generate_juce_header(ChendaPlugin)

juce_add_binary_data(ChendaPluginData
    SOURCES Resources/kick.wav
)

target_link_libraries(ChendaPlugin PRIVATE
    ChendaPluginData
    juce::juce_audio_utils
    juce::juce_audio_processors
    juce::juce_dsp
    juce::juce_recommended_config_flags
    juce::juce_recommended_warning_flags
)