/*--------------------------------------------------------------------
 * (C) Copyright 2006-2012 Barcelona Supercomputing Center
 *                        Centro Nacional de Supercomputacion
 * 
 * This file is part of Mercurium C/C++ source-to-source compiler.
 * 
 * See AUTHORS file in the top level directory for information
 * regarding developers and contributors.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 * 
 * Mercurium C/C++ source-to-source compiler is distributed in the hope
 * that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with Mercurium C/C++ source-to-source compiler; if
 * not, write to the Free Software Foundation, Inc., 675 Mass Ave,
 * Cambridge, MA 02139, USA.
--------------------------------------------------------------------*/



/*
 <testinfo>
 test_generator=config/mercurium-analysis
 test_ignore="yes"
 test_ignore_reason="Fails after merging analysis"
 </testinfo>
*/

#include <stdlib.h>

int foo(int p)
{
    #pragma analysis_check assert upper_exposed(p)
    return p;
}

int bar(int p)
{
    #pragma analysis_check assert upper_exposed(p)
    return p;
}

int function(int (*fun)(int), int p)
{
    #pragma analysis_check assert undefined(p)
    return (*fun)(p);
}

int main(int argc, char *argv[])
{
    int a, b;
    
    #pragma analysis_check assert upper_exposed(argc) defined(argc, a)
    a = function((int (*)(int))foo, argc++);
    #pragma analysis_check assert upper_exposed(argc) defined(argc, b)
    b = function((int (*)(int))bar, argc++);
    
    #pragma analysis_check assert upper_exposed(a, b)
    if( a != 1 || b != 2 )
        exit( 1 );
    return 0;
}
