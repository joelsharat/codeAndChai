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
    driveControlKnob.addListener(this);
    driveControlKnob.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    driveControlKnob.setBounds(30, 75, 40, 40);
    driveControlKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 20, 25);
    driveControlKnob.setRange(0.01f, 10);
    addAndMakeVisible(driveControlKnob);
    driveControlKnob.setValue(audioProcessor.driveValue);
    
    //tone control
    toneControlKnob.addListener(this);
    toneControlKnob.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    toneControlKnob.setBounds(130, 75, 40, 40);
    toneControlKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 20, 25);
    toneControlKnob.setRange(0.01, 10);
    addAndMakeVisible(toneControlKnob);
    toneControlKnob.setValue(audioProcessor.toneValue);
    
  
    //level control
    levelControlKnob.addListener(this);
    levelControlKnob.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    levelControlKnob.setBounds(230, 75, 40, 40);
    levelControlKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 20, 25);
    levelControlKnob.setRange(0.01, 10);
    levelControlKnob.setValue(audioProcessor.levelValue);
    addAndMakeVisible(levelControlKnob);
    
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
    g.drawFittedText("By JSFX",270, 100, 70, 70,juce::Justification::centred, 1);
    
    
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId))
   // g.setColour (juce::Colours::orange);
   // g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void KlonPedalPluginAudioProcessorEditor::resized()
{
    driveControlKnob.setBounds(30, 75, 40, 40);
    toneControlKnob.setBounds(130, 75, 40, 40);
    levelControlKnob.setBounds(230, 75, 40, 40);
}

void KlonPedalPluginAudioProcessorEditor::sliderValueChanged(Slider *slider){
    if(slider == &driveControlKnob){
        audioProcessor.driveValue = driveControlKnob.getValue();
    }
    if  (slider == &toneControlKnob){
         audioProcessor.toneValue = toneControlKnob.getValue();
    }
    
    if(slider == &levelControlKnob) {
         audioProcessor.levelValue = levelControlKnob.getValue();
    
    }
}







