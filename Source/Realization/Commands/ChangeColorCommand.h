//
// Created by Vlad on 12/10/18.
//

#ifndef ARCHITECTURE_CHANGECOLORCOMMAND_H
#define ARCHITECTURE_CHANGECOLORCOMMAND_H

#include <memory>
#include <map>

#include "Command.h"
#include "Common/Color.h"

class Primitive;
class Editor;

class ChangeColorCommand : public Command
{
public:
    ChangeColorCommand(std::shared_ptr<Editor> editor, const Color& newColor);
    ~ChangeColorCommand() override = default;

    void undo() override;
    void execute() override;

private:
    bool m_commandWasExecuted;
    std::shared_ptr<Editor> m_editor;
    std::map<std::shared_ptr<Primitive>, Color> m_primitivesWithOldColors;
    const Color m_newColor;
};

#endif //ARCHITECTURE_CHANGECOLORCOMMAND_H