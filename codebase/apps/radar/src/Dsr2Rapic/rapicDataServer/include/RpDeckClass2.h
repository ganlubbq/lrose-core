
//////////////////////////////////////////////////////////////
//
// Header file for RpDeckClass2
//
//    This file is generated by RapidApp 1.2
//
//    This class is derived from VkTabbedDeck
//
//    When you modify this header file, limit your changes to those
//    areas between the "//---- Start/End editable code block" markers
//
//    This will allow the builder to integrate changes more easily
//
//    This class is a ViewKit user interface "component".
//    For more information on how components are used, see the
//    "ViewKit Programmers' Manual", and the RapidApp
//    User's Guide.
//////////////////////////////////////////////////////////////
#ifndef RPDECKCLASS2_H
#define RPDECKCLASS2_H
#include <Vk/VkTabbedDeck.h>
//---- Start editable code block: headers and declarations


//---- End editable code block: headers and declarations



//---- RpDeckClass2 class declaration

class RpDeckClass2 : public VkTabbedDeck
{

  public:

    RpDeckClass2 ( const char *, Widget );
    RpDeckClass2 ( const char * );
    ~RpDeckClass2();
    const char *  className();

    //---- Start editable code block: RpDeckClass2 public


    //---- End editable code block: RpDeckClass2 public



    protected:


    // Classes created by this class

    class RpCursorDataFormClass *_rpCursorDataFormClassUI;
    class RpSeqSpdDepthFormClass *_rpSeqSpdDepthFormClassUI;

    // Widgets created by this class

    Widget  _rpDeckClass1;


    //---- Start editable code block: RpDeckClass2 protected


    //---- End editable code block: RpDeckClass2 protected



  private: 

    // Array of default resources

    static String      _defaultRpDeckClass2Resources[];

    //---- Start editable code block: RpDeckClass2 private


    //---- End editable code block: RpDeckClass2 private
};
//---- Start editable code block: End of generated code


//---- End editable code block: End of generated code

#endif
