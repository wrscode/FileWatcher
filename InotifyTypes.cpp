/*
 * File name: InotifyTypes.cpp
 * author: wrscode
 */

#include "InotifyTypes.h"

namespace Inotify {

std::ostream& operator<<(std::ostream& os, const Mask& rhs) {

    if (rhs && Mask::ACCESS) {
        os << "Mask::ACCESS ";
    }
    if (rhs && Mask::MODIFY) {
        os << "Mask::MODIFY ";
    }
    if (rhs && Mask::ATTRIB) {
        os << "Mask::ATTRIB ";
    }
    if (rhs && Mask::CLOSE_WRITE) {
        os << "Mask::CLOSE_WRITE ";
    }
    if (rhs && Mask::CLOSE_NOWRITE) {
        os << "Mask::CLOSE_NOWRITE ";
    }
    if (rhs && Mask::OPEN) {
        os << "Mask::OPEN ";
    }
    if (rhs && Mask::MOVED_FROM) {
        os << "Mask::MOVED_FROM ";
    }
    if (rhs && Mask::MOVED_TO) {
        os << "Mask::MOVED_TO ";
    }
    if (rhs && Mask::MOVE_SELF) {
        os << "Mask::MOVE_SELF ";
    }
    if (rhs && Mask::CREATE) {
        os << "Mask::CREATE ";
    }
    if (rhs && Mask::DELETE) {
        os << "Mask::DELETE ";
    }
    if (rhs && Mask::DELETE_SELF) {
        os << "Mask::DELETE_SELF ";
    }
    if (rhs && Mask::UNMOUNT) {
        os << "Mask::UNMOUNT ";
    }
    if (rhs && Mask::Q_OVERFLOW) {
        os << "Mask::Q_OVERFLOW ";
    }
    if (rhs && Mask::IGNORED) {
        os << "Mask::IGNORED ";
    }
    if (rhs && Mask::ONLYDIR) {
        os << "Mask::ONLYDIR ";
    }
    if (rhs && Mask::DONT_FOLLOW) {
        os << "Mask::DONT_FOLLOW ";
    }
    if (rhs && Mask::EXCL_UNLINK) {
        os << "Mask::EXCL_UNLINK ";
    }
    if (rhs && Mask::MASK_ADD) {
        os << "Mask::MASK_ADD ";
    }
    if (rhs && Mask::ISDIR) {
        os << "Mask::ISDIR ";
    }
    if (rhs && Mask::ONESHOT) {
        os << "Mask::ONESHOT ";
    }
    return os;
}

}  // namespace Inotify
