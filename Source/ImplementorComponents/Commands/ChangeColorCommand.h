//
// Created by Vlad on 12/10/18.
//

#ifndef ARCHITECTURE_CHANGECOLORCOMMAND_H
#define ARCHITECTURE_CHANGECOLORCOMMAND_H

#include <memory>
#include <map>

#include "ICommand.h"
#include "Common/Color.h"

class IPrimitive;
class IImplementor;

class ChangeColorCommand : public ICommand
{
public:
    ChangeColorCommand(std::shared_ptr<IImplementor> editor, const Color& newColor);

    void undo() override;
    void execute() override;

private:
    bool m_commandWasExecuted;
    std::shared_ptr<IImplementor> m_editor;
    std::map<std::shared_ptr<IPrimitive>, Color> m_primitivesWithOldColors;
    const Color m_newColor;
};

#endif //ARCHITECTURE_CHANGECOLORCOMMAND_H