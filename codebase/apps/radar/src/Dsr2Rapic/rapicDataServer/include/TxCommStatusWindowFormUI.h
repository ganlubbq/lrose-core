
//////////////////////////////////////////////////////////////
//
// Header file for TxCommStatusWindowFormUI
//
//    This file is generated by RapidApp 1.2
//
//    This class implements the user interface portion of a class
//    Normally it is not used directly.
//    Instead the subclass, TxCommStatusWindowForm is instantiated
//
//    To extend or alter the behavior of this class, you should
//    modify the TxCommStatusWindowForm files
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
#ifndef TXCOMMSTATUSWINDOWFORMUI_H
#define TXCOMMSTATUSWINDOWFORMUI_H
#include <Vk/VkComponent.h>


//---- Start editable code block: headers and declarations


//---- End editable code block: headers and declarations


// Externally defined classes referenced by this class:

class TxCommStatusForm;


class TxCommStatusWindowFormUI : public VkComponent
{ 

  public:

    TxCommStatusWindowFormUI ( const char *, Widget );
    TxCommStatusWindowFormUI ( const char * );
    ~TxCommStatusWindowFormUI();
    void create ( Widget );
    const char *  className();

    //---- Start editable code block: TxCommStatusWindowForm public


    //---- End editable code block: TxCommStatusWindowForm public


  protected:


    // Classes created by this class

    class TxCommStatusForm *_txCommStatusForm2;

    // Widgets created by this class

    Widget  _button48;
    Widget  _txCommStatusWindowForm;


    //---- Start editable code block: TxCommStatusWindowForm protected


    //---- End editable code block: TxCommStatusWindowForm protected


  private: 

    // Array of default resources

    static String      _defaultTxCommStatusWindowFormUIResources[];

    //---- Start editable code block: TxCommStatusWindowForm private


    //---- End editable code block: TxCommStatusWindowForm private
};
//---- Start editable code block: End of generated code


//---- End editable code block: End of generated code

#endif
