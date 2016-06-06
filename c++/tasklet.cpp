/****************************************************************************
 *
 *  Copyright (c) 2016, Michael Becker (michael.f.becker@gmail.com)
 *
 *  This file is part of the FreeRTOS C++ Wrappers project.
 *
 *  The FreeRTOS C++ Wrappers project is free software: you can redistribute
 *  it and/or modify it under the terms of the GNU General Public License as
 *  published by the Free Software Foundation, version 3 of the License.
 *
 *  The FreeRTOS C++ Wrappers project is distributed in the hope that it will
 *  be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with the FreeRTOS C++ Wrappers project.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 ***************************************************************************/
#include "tasklet.hpp"


using namespace rtos_cpp;


Tasklet::Tasklet()
{
}


Tasklet::~Tasklet()
{
}


void Tasklet::TaskletAdapterFunction(void *reference, uint32_t parameter)
{
    Tasklet *tasklet = static_cast<Tasklet *>(reference);

    tasklet->run(parameter);
}


bool Tasklet::Schedule( uint32_t parameter,
                        TickType_t CmdTimeout)
{
    BaseType_t rc;

    rc = xTimerPendFunctionCall(TaskletAdapterFunction,
                                this,
                                parameter,
                                xTicksToWait);

    return rc == pdPASS : true ? false;
}


bool Tasklet::ScheduleFromISR(  uint32_t parameter,
                                BaseType_t *pxHigherPriorityTaskWoken)
{
    BaseType_t rc;

    rc = xTimerPendFunctionCallFromISR( TaskletAdapterFunction,
                                        this,
                                        parameter,
                                        pxHigherPriorityTaskWoken);

    return rc == pdPASS : true ? false;
}
