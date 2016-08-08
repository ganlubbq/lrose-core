
//////////////////////////////////////////////////////////////
//
// Header file for FormUI
//
//    This file is generated by RapidApp 1.2
//
//    This class implements the user interface portion of a class
//    Normally it is not used directly.
//    Instead the subclass, Form is instantiated
//
//    To extend or alter the behavior of this class, you should
//    modify the Form files
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
#ifndef FORMUI_H
#define FORMUI_H
#include <Vk/VkComponent.h>


//---- Start editable code block: headers and declarations


//---- End editable code block: headers and declarations


// Externally defined classes referenced by this class:

class RpTabbedDeckClass;
class RpmainSeqFormClass;


class FormUI : public VkComponent
{ 

  public:

    FormUI ( const char *, Widget );
    FormUI ( const char * );
    ~FormUI();
    void create ( Widget );
    const char *  className();

    //---- Start editable code block: Form public


    //---- End editable code block: Form public


  protected:


    // Classes created by this class

    class RpTabbedDeckClass *_rpTabbedDeckClass;
    class RpmainSeqFormClass *_rpmainSeqFormClassUI;

    // Widgets created by this class

    Widget  _form;


    //---- Start editable code block: Form protected


    //---- End editable code block: Form protected


  private: 

    // Array of default resources

    static String      _defaultFormUIResources[];

    //---- Start editable code block: Form private


    //---- End editable code block: Form private
};
//---- Start editable code block: End of generated code


//---- End editable code block: End of generated code

#endif
