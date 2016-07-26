# freertos-addons

After working with FreeRTOS for over 6 years now, I've decided to start adding features and implementations that I wish would have been there at the beginning.

## Current Features

+ C++ Wrappers 
  - A collection of C++ wrappers encapsulating FreeRTOS functionality, allowing you to write your RTOS application in C++ while still using FreeRTOS. This wrapper layer does all the integration work for you.
  - Everything was testing successfully using FreeRTOS versions 8.2.3 and 9.0.0.
  - There are currently 18 demo / unit test projects using these wrappers.

+ Updated Linux port 
  - An update of the Linux / POSIX port of FreeRTOS
  - This update was tested successfully with FreeRTOS 8.2.3 and 9.0.0 
  - Two Ubuntu workstations were also used, running 16.04 and 14.04, both 64-bit multicore machines. 
  - This revised Posix port I renamed to Linux port, since I ended up using a few Linux specific APIs in it.
  - Thanks to William Davy who wrote the original Posix FreeRTOS port. He did amazing work simulating a real-time system under Linux.

## Releases

### Version 1.0.1
Changed license from GPLv3 to GPLv2 (or later) to accomodate FreeRTOS's modified GPLv2 license.
See https://www.gnu.org/licenses/gpl-faq.html#AllCompatibility for more information.

### Version 1.0.0 
Initial release.

## TODO

### FreeRTOS Features Not Yet Implemented
+ events
+ MPU restricted threads
+ eTaskGetState
+ uxTaskGetNumberOfTasks
+ uxTaskGetStackHighWaterMark
+ Thread Local Storage

### New Value Added
+ In Timers, add OnStop / OnStart / mutex sync with these methods?
+ Work Queues
+ Fixed size Memory pools
+ Priority queues
+ Monitors 
+ Condition Variables
+ Tick Hooks - option to round robin hooks, one per tick


