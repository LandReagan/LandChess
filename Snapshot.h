#ifndef SNAPSHOT_H_INCLUDED
#define SNAPSHOT_H_INCLUDED

/*
    Class designed for exchange of information between model and view
    Consists of a vector of formatted string
    Could be used as well for:
    - saves
    - game records
    - initial game situation

    FORMAT: "xx:x:x:xx" - all converted to char
    stands for :    xx  - Case col & lin
                    x   - Case color
                    x   - Case status
                    xx  - Piece nature and color.
*/

#include <string>
#include <vector>

class Snapshot
{
public:
    Snapshot() {}
    virtual ~Snapshot() {v_snap.clear();}

//(public)
    std::vector<std::string> v_snap;
};

#endif // SNAPSHOT_H_INCLUDED
