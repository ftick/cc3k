#!/bin/bash

prog=$1
guard="__$(echo $prog | tr '[:lower:]' '[:upper:]')_H__"

shift

cat <<Doc
#ifndef $guard
#define $guard

class $prog $@ {
  public:
    ${prog}();
};

#endif
Doc
