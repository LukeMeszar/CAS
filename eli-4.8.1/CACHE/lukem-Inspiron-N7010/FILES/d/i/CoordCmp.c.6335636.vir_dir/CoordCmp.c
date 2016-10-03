
#include "CoordCmp.h"

static POSITION _FirstCoord = {1, 1};
CoordPtr FirstCoord = (CoordPtr)&_FirstCoord;

#if defined(__cplusplus) || defined(__STDC__)
int CoordLess (CoordPtr coord1, CoordPtr coord2)
#else
int CoordLess (coord1, coord2)
        CoordPtr        coord1, coord2;
#endif
{
return ((coord1->line == coord2->line)?
                (coord1->col < coord2->col):
                (coord1->line < coord2->line));
}

#if defined(__cplusplus) || defined(__STDC__)
int CoordLessEqual (CoordPtr coord1, CoordPtr coord2)
#else
int CoordLessEqual (coord1, coord2)
        CoordPtr        coord1, coord2;
#endif
{
return ((coord1->line == coord2->line)?
                (coord1->col <= coord2->col):
                (coord1->line < coord2->line));
}
