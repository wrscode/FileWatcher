#include <iostream>

#include "file.h"
#include "Inotify.h"
#include "InotifyTypes.h"
#include "InotifyEventIterator.h"
#include "InotyfyWatcher.h"

#define UNUSED(x)   (void)((x))

int main(int argc, char **argv) {

    UNUSED(argc);
    UNUSED(argv);

    Inotify::Inotify Ino(2048);
    Ino.init();
    Inotify::Watcher w0("/home/wrscode/", Inotify::Mask::MODIFY | Inotify::Mask::CREATE | Inotify::Mask::DELETE);

    Ino.addWatch(w0);

    while (true) {
        auto EventIt = Ino.getEvents();

        do {
            std::cout << EventIt.getRaw()->name << std::endl;
            Inotify::Watcher::RPtr WPtr = EventIt.getWatcher();
            std::cout << WPtr->getPath() << std::endl;

        } while (EventIt.next());
    }
}
