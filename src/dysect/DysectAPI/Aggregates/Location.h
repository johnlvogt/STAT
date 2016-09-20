/*
Copyright (c) 2013-2014, Lawrence Livermore National Security, LLC.
Produced at the Lawrence Livermore National Laboratory.
Written by Niklas Nielsen, Gregory Lee [lee218@llnl.gov], Dong Ahn.
LLNL-CODE-645136.
All rights reserved.

This file is part of DysectAPI. For details, see https://github.com/lee218llnl/DysectAPI. Please also read dysect/LICENSE

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (as published by the Free Software Foundation) version 2.1 dated February 1999.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the IMPLIED WARRANTY OF MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the terms and conditions of the GNU General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef __DYSECTAPI_LOCATION_H
#define __DYSECTAPI_LOCATION_H

#include <string>
#include <vector>

#include "DysectAPI/Aggregates/AggregateFunction.h"
#include "DysectAPI/Aggregates/StrAgg.h"

namespace DysectAPI {
  class FuncLocation : public StrAgg {
     
  public:
    FuncLocation(int id, int count, std::string fmt, void* payload);
    FuncLocation();

    bool collect(void* process, void* thread);
    
    bool print();
  };

  class FileLocation : public StrAgg {
  public:
    FileLocation(int id, int count, std::string fmt, void* payload);
    FileLocation();

    bool collect(void* process, void* thread);
    
    bool print();
  };

  class FuncParamNames : public StrAgg {
    std::vector<AggregateFunction*> paramBounds;

  public:
    
    FuncParamNames(int id, int count, std::string fmt, void* payload);
    FuncParamNames();

    bool collect(void* process, void* thread);
    
    bool print();
  };

  class StackTraces : public StrAgg {
  public:
    
    StackTraces(int id, int count, std::string fmt, void* payload);
    StackTraces();

    bool collect(void* process, void* thread);
    
    bool print();
  };

  class StaticStr : public StrAgg {
    
  public:
    StaticStr(int id, int count, std::string fmt, void* payload);
    StaticStr();

    bool addStr(std::string str);

    bool collect(void* process, void* thread);

    bool print();
  };
}

#endif
