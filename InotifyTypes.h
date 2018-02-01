/*
 * File name: InotifyTypes.h
 * author: wrscode
 */

#ifndef INOTIFYTYPES_H_
#define INOTIFYTYPES_H_

#include <type_traits>
#include <iostream>
#include <sys/types.h>
#include <sys/inotify.h>

namespace Inotify {
enum class Mask : uint32_t {
    ACCESS = IN_ACCESS,
    MODIFY = IN_MODIFY,
    ATTRIB = IN_ATTRIB,
    CLOSE_WRITE = IN_CLOSE_WRITE,
    CLOSE_NOWRITE = IN_CLOSE_NOWRITE,
    OPEN = IN_OPEN,
    MOVED_FROM = IN_MOVED_FROM,
    MOVED_TO = IN_MOVED_TO,
    CREATE = IN_CREATE,
    DELETE = IN_DELETE,
    DELETE_SELF = IN_DELETE_SELF,
    MOVE_SELF = IN_MOVE_SELF,
    UNMOUNT = IN_UNMOUNT,
    Q_OVERFLOW = IN_Q_OVERFLOW,
    IGNORED = IN_IGNORED,
    ONLYDIR = IN_ONLYDIR,
    DONT_FOLLOW = IN_DONT_FOLLOW,
    EXCL_UNLINK = IN_EXCL_UNLINK,
    MASK_ADD = IN_MASK_ADD,
    ISDIR = IN_ISDIR,
    ONESHOT = IN_ONESHOT,
    ALL_EVENTS = IN_ALL_EVENTS,
};

constexpr std::uint32_t cast(const Mask hs) {
    return static_cast<std::uint32_t>(hs);
}

constexpr Mask cast(const std::uint32_t& hs) {
    return static_cast<Mask>(hs);
}

constexpr Mask operator|(const Mask& lhs, const Mask& rhs) {
    return static_cast<Mask>(cast(lhs) | cast(rhs));
}

constexpr Mask operator&(const Mask& lhs, const Mask& rhs) {
    return static_cast<Mask>(cast(lhs) & cast(rhs));
}

constexpr bool operator&&(const Mask& lhs, const Mask& rhs) {
    return (cast(lhs) & cast(rhs)) == cast(rhs);
}

std::ostream& operator<<(std::ostream& os, const Mask& rhs);

}

#endif /* INOTIFYTYPES_H_ */
