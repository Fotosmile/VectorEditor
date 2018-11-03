#include <iostream>
#include "Common/CommonDefines.h"
#include <memory>
#include <stdexcept>
#include <iostream>

#include "Abstraction/Abstraction.h"
#include "ImplementorComponents/Implementor/Implementor.h"
#include "Mock/MockControlElements.h"

void runCallbacksListening();

int main()
{
    std::cout << "Hello, World!" << std::endl;

    try
    {
        std::shared_ptr<IImplementor> editor = std::make_shared<Implementor>();
        std::unique_ptr<IAbstraction> guiMediator = std::make_unique<Abstraction>(editor);

        runCallbacksListening();
    }
    catch (const std::exception& exc)
    {
        std::cout << "Failed to run the program: " << exc.what() << std::endl;
    }

    return 0;
}

void runCallbacksListening()
{

    for (;;)
    {
        std::size_t controlElementType = 1;
        std::size_t callbackIndex = 0;
        std::string input;
        int x = 0;
        int y = 0;
        std::cout << "Select control element type: ";
        std::cout << "\n1) Button";
        std::cout << "\n2) Label";
        std::cout << "\n3) LineEdit";
        std::cout << "\n4) Window";
        std::cout << "\n5) Exit";
        std::cout << std::endl;

        std::cout << "Control element type: ";
        std::cin >> controlElementType;
        if (controlElementType == 5)
        {
            break;
        }
        if (controlElementType < 0 || controlElementType > 5)
        {
            continue;
        }

        std::cout << "Index of control element callback: ";
        std::cin >> callbackIndex;

        try
        {
            switch (controlElementType)
            {
                case 1:
                    MockControlElements::Instance().runButtonClick(callbackIndex);
                    break;
                case 2:
                    MockControlElements::Instance().runLabelClick(callbackIndex);
                    break;
                case 3:
                    std::cout << "Input: ";
                    std::cin >> input;
                    MockControlElements::Instance().runLineEditInput(callbackIndex, input);
                    break;
                case 4:
                    std::cout << "x, y: ";
                    std::cin >> x >> y;
                    MockControlElements::Instance().runWindowClick(callbackIndex, x, y);
                    break;
                default:
                    throw std::runtime_error ("Invalid control element type");
            }
        }
        catch (const std::exception& exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }
}