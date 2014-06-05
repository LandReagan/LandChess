#include "Case.h"

void
Case::update_snap_state() // Check for format in Snapshot class xx:x:x:xx
{
    std::string loc_str;
    loc_str.push_back(col);
    loc_str.push_back('0' + lin);
    loc_str.push_back(':');
    loc_str.push_back('0' + (char)is_white);
    loc_str.push_back(':');
    loc_str.push_back('0' + (char)status);
    loc_str.push_back(':');

    if (piece != nullptr)
        {
            loc_str.push_back(piece->get_nature());
            loc_str.push_back(piece->get_color());
        }

    //std::clog << "Snapshot update : " << loc_str << std::endl;

    snap_state.clear();
    snap_state.append(loc_str);
}
