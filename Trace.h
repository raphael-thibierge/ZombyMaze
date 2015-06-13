//
//  Trace.h
//  Console
//
//  Created by Raphael Thibierge on 13/06/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __Console__Trace__
#define __Console__Trace__

#include <stdio.h>
#include "GraphicsElement.h"



class Trace : protected GraphicElement
{
private:
    
    std::list<Trace> _tracesList;

// ACCESSORS
public:
    std::list<Trace> getTraceList() const {return _tracesList;};
};


#endif /* defined(__Console__Trace__) */
