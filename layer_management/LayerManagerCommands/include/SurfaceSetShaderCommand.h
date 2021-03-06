/***************************************************************************
*
* Copyright 2010,2011 BMW Car IT GmbH
*
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*        http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
****************************************************************************/

#ifndef _SURFACESETSHADERCOMMAND_H_
#define _SURFACESETSHADERCOMMAND_H_

#include "ICommand.h"

class SurfaceSetShaderCommand : public ICommand
{
public:
    /*!
     * \action    This command applies a shader to a surface within the GENIVI
     *            LayerManagement
     * \frequency Typically once during surface creation. May be used during
     *            runtime for effects.
     * \param[in] sender process id of application that sent this command
     * \param[in] id id of surface
     * \param[in] shaderid id of shader
     * \ingroup Commands
     */
    SurfaceSetShaderCommand(pid_t sender, unsigned int id, unsigned int shaderid)
    : ICommand(ExecuteSynchronous, sender)
    , m_id(id)
    , m_shaderid(shaderid)
    {}

    /**
     * \brief default destructor
     */
    virtual ~SurfaceSetShaderCommand() {}

    /**
     * \brief Execute this command.
     * \param[in] executor Pointer to instance executing the LayerManagement COmmands
     * \return ExecutionSuccess: execution successful
     * \return ExecutionSuccessRedraw: execution successful and screen needs to be redrawn
     * \return ExecutionFailed: execution failed
     * \return ExecutionFailedRedraw: execution unsuccessful and screen needs to be redrawn
     */
    virtual ExecutionResult execute(ICommandExecutor* executor);

    /**
     * \brief Get description string for this command.
     * \return String object with description of this command object
     */
    virtual const std::string getString();

    unsigned int getID() const;
    unsigned int getShaderID() const;

private:
    const unsigned int m_id;
    const unsigned int m_shaderid;
};

#endif /* _SURFACESETSHADERCOMMAND_H_ */

