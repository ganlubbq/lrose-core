
//////////////////////////////////////////////////////////////
//
// Header file for RpSeqSpdDepthFormClass
//
//    This file is generated by RapidApp 1.2
//
//    This class is derived from RpSeqSpdDepthFormClassUI which 
//    implements the user interface created in 
//    RapidApp. This class contains virtual
//    functions that are called from the user interface.
//
//    When you modify this header file, limit your changes to those
//    areas between the "//---- Start/End editable code block" markers
//
//    This will allow RapidApp to integrate changes more easily
//
//    This class is a ViewKit user interface "component".
//    For more information on how components are used, see the
//    "ViewKit Programmers' Manual", and the RapidApp
//    User's Guide.
//////////////////////////////////////////////////////////////
#ifndef RPSEQSPDDEPTHFORMCLASS_H
#define RPSEQSPDDEPTHFORMCLASS_H
#include "RpSeqSpdDepthFormClassUI.h"
//---- Start editable code block: headers and declarations


//---- End editable code block: headers and declarations


//---- RpSeqSpdDepthFormClass class declaration

class RpSeqSpdDepthFormClass : public RpSeqSpdDepthFormClassUI
{

  public:

    RpSeqSpdDepthFormClass ( const char *, Widget );
    RpSeqSpdDepthFormClass ( const char * );
    ~RpSeqSpdDepthFormClass();
    const char *  className();

    static VkComponent *CreateRpSeqSpdDepthFormClass( const char *name, Widget parent ); 

    //---- Start editable code block: RpSeqSpdDepthFormClass public

    void SetValues();
    void SetSeqMem(int mem = -1);
    void SetSeqMemLimit(int memlimit = -1);
    int SetSeqSize(int sz = -1);


    //---- End editable code block: RpSeqSpdDepthFormClass public



  protected:


    // These functions will be called as a result of callbacks
    // registered in RpSeqSpdDepthFormClassUI

    virtual void SeqStep10min ( Widget, XtPointer );
    virtual void SeqStep3min ( Widget, XtPointer );
    virtual void SeqStep5min ( Widget, XtPointer );
    virtual void newseqdepthLimit ( Widget, XtPointer );
    virtual void newseqmemLimit ( Widget, XtPointer );
    virtual void newseqspeedValue ( Widget, XtPointer );

    //---- Start editable code block: RpSeqSpdDepthFormClass protected


    //---- End editable code block: RpSeqSpdDepthFormClass protected



  private:

    static void* RegisterRpSeqSpdDepthFormClassInterface();

    //---- Start editable code block: RpSeqSpdDepthFormClass private


    //---- End editable code block: RpSeqSpdDepthFormClass private


};
//---- Start editable code block: End of generated code


//---- End editable code block: End of generated code

#endif
