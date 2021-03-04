/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
KlonPedalPluginAudioProcessorEditor::KlonPedalPluginAudioProcessorEditor (KlonPedalPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (300, 150);
    
    //drive control
    driveControl.addListener(this);
    driveControl.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    driveControl.setBounds(30, 75, 40, 40);
    driveControl.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 20, 25);
    driveControl.setRange(0.01f, 10);
    //driveControl.setValue();
    addAndMakeVisible(driveControl);
    
    //tone control
    toneControl.addListener(this);
    toneControl.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    toneControl.setBounds(130, 75, 40, 40);
    toneControl.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 20, 25);
    toneControl.setRange(0.01, 10);
    //toneControl.setValue();
    addAndMakeVisible(toneControl);
    
    //level control
    levelControl.addListener(this);
    levelControl.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    levelControl.setBounds(230, 75, 40, 40);
    levelControl.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 20, 25);
    levelControl.setRange(0.01, 10);
    //levelControl.setValue();
    addAndMakeVisible(levelControl);
    
}

KlonPedalPluginAudioProcessorEditor::~KlonPedalPluginAudioProcessorEditor()
{
}

//==============================================================================
void KlonPedalPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::orange);
    g.setFont(15.f);
    g.drawFittedText("Jlon Mentour",100, 10, 50, 20,juce::Justification::centred, 1);
    
    g.setFont(20.f);
    g.drawFittedText("By JSFX",270, 100, 50, 20,juce::Justification::centred, 1);
    
    
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId))
   // g.setColour (juce::Colours::orange);
   // g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void KlonPedalPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void KlonPedalPluginAudioProcessor::driveControlChange(juce::Slider* slider){
    if(slider == &driveControl){
        KlonPedalPluginAudioProcessor.driveControl = slider -> getValue();
        
    }
}

void KlonPedalPluginAudioProcessor::toneControlChange(juce::Slider* slider){
    if(slider == &driveControl){
        KlonPedalPluginAudioProcessor.toneControl = slider -> getValue();
        
    }
}


void KlonPedalPluginAudioProcessor::levelControlChange(juce::Slider* slider){
    if(slider == &driveControl){
        KlonPedalPluginAudioProcessor.levelControl = slider -> getValue();
        
    }
}

