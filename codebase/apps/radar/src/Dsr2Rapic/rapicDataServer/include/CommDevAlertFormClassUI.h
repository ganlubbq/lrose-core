
//////////////////////////////////////////////////////////////
//
// Header file for CommDevAlertFormClassUI
//
//    This file is generated by RapidApp 1.2
//
//    This class implements the user interface portion of a class
//    Normally it is not used directly.
//    Instead the subclass, CommDevAlertFormClass is instantiated
//
//    To extend or alter the behavior of this class, you should
//    modify the CommDevAlertFormClass files
//
//    Restrict changes to those sections between
//    the "//--- Start/End editable code block" markers
//
//    This will allow RapidApp to integrate changes more easily
//
//    This class is a ViewKit user interface "component".
//    For more information on how components are used, see the
//    "ViewKit Programmers' Manual", and the RapidApp
//    User's Guide.
//
//////////////////////////////////////////////////////////////
#ifndef COMMDEVALERTFORMCLASSUI_H
#define COMMDEVALERTFORMCLASSUI_H
#include <Vk/VkComponent.h>


//---- Start editable code block: headers and declarations


//---- End editable code block: headers and declarations


class CommDevAlertFormClassUI : public VkComponent
{ 

  public:

    CommDevAlertFormClassUI ( const char *, Widget );
    CommDevAlertFormClassUI ( const char * );
    ~CommDevAlertFormClassUI();
    void create ( Widget );
    const char *  className();

    //---- Start editable code block: CommDevAlertFormClass public


    //---- End editable code block: CommDevAlertFormClass public


  protected:


    // Widgets created by this class

    Widget  _alertPostedTimeLabel;
    Widget  _alertScrolledText;
    Widget  _alertTitleLabel;
    Widget  _commDevAlertFormClassUI;
    Widget  _devNameLabel;
    Widget  _label32;
    Widget  _label39;
    Widget  _scrolledWindow7;
    Widget  _silenceAlerttoggle;


    //---- Start editable code block: CommDevAlertFormClass protected


    //---- End editable code block: CommDevAlertFormClass protected


  private: 

    // Array of default resources

    static String      _defaultCommDevAlertFormClassUIResources[];

    //---- Start editable code block: CommDevAlertFormClass private


    //---- End editable code block: CommDevAlertFormClass private
};
//---- Start editable code block: End of generated code


//---- End editable code block: End of generated code

#endif
