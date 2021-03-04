/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class KlonPedalPluginAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                             public juce::Slider::Listener
{
public:
    KlonPedalPluginAudioProcessorEditor (KlonPedalPluginAudioProcessor&);
    ~KlonPedalPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void driveControlChange(juce::Slider* slider)override;
    void toneControlChange(juce::Slider* slider)override;
    void levelControlChange(juce::Slider* slider )override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    KlonPedalPluginAudioProcessor& audioProcessor;
    
   juce::Slider driveControl;
   juce::Slider toneControl;
   juce::Slider levelControl;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KlonPedalPluginAudioProcessorEditor)
};
