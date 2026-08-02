# Chenda VST Plugin

A VST3 instrument plugin for authentic Chenda percussion, built with [JUCE](https://juce.com).

The Chenda is a cylindrical drum from Kerala, India, used in Theyyam, Kathakali, and Panchavadyam. This plugin aims to bring its distinct sharp, high-tension sound into any VST3-compatible DAW.

---

## Status

Early development. Currently plays a single sample on any MIDI note. Articulation mapping, velocity layers, and round-robin are in progress.

---

## Requirements

- Windows 10/11
- Visual Studio 2022 with the **Desktop development with C++** workload
- [JUCE](https://github.com/juce-framework/JUCE) at `C:/JUCE`
- CMake 3.22+ (included with Visual Studio)
- A VST3-compatible DAW for testing (Ableton Live 11+, REAPER, etc.)

---

## Building

```bash
# Clone the repo
git clone https://github.com/arjungkk/chenda-plugin.git
cd chenda-plugin

# Open in Visual Studio
# File → Open → CMake → select CMakeLists.txt
# Set build target to ChendaPlugin_Standalone
# Press F5
```

The **Standalone** build runs without a DAW and is the recommended way to test during development. For DAW testing, build the **VST3** target and point your DAW's plugin folder to:

```
out/build/x64-Debug/ChendaPlugin_artefacts/Debug/VST3/
```

---

## MIDI Note Mapping

| Note | Number | Articulation          |
|------|---------|-----------------------|
| C2   | 36      | Right face, center    |
| D2   | 38      | Right face, edge      |
| E2   | 40      | Right face, muted     |
| F2   | 41      | Left face, open       |
| G2   | 43      | Left face, muted      |
| A2   | 45      | Rim shot              |
| B2   | 47      | Ghost / grace note    |

---

## Project Structure

```
chenda-plugin/
├── CMakeLists.txt
├── Resources/
│   └── kick.wav                  # Placeholder sample (to be replaced)
└── Source/
    ├── PluginProcessor.h / .cpp  # AudioProcessor, MIDI routing, synth
    ├── PluginEditor.h / .cpp     # Plugin UI
    ├── ChendaSynthesiser.h/.cpp  # juce::Synthesiser subclass (planned)
    ├── ChendaSound.h / .cpp      # Per-stroke sample data (planned)
    ├── ChendaVoice.h / .cpp      # Voice rendering (planned)
    ├── StrokeMapper.h / .cpp     # MIDI note → articulation (planned)
    └── DspChain.h / .cpp         # Transient shaper, EQ, IR (planned)
```

---

## Roadmap

- [x] Project scaffold and build pipeline
- [x] Single sample playback via MIDI
- [ ] Articulation mapping (note → stroke type)
- [ ] Velocity layers (4 per articulation)
- [ ] Round-robin sample selection
- [ ] DSP chain: transient shaper, EQ, body IR convolution
- [ ] Plugin UI
- [ ] Expand to full Indian percussion suite (Mridangam, Tabla, Tavil)

---

## License

TBD