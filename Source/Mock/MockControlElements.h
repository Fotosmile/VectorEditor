//
// Created by Vlad on 20/10/18.
//

#ifndef ARCHITECTURE_MOCKLINUXCONTROLELEMENTS_H
#define ARCHITECTURE_MOCKLINUXCONTROLELEMENTS_H

#include <functional>
#include <vector>
#include <string>
#include <memory>
#include <list>

class RasterImage;
class Primitive;

class MockControlElements
{
public:
    MockControlElements(const MockControlElements&) = delete;
    MockControlElements& operator=(const MockControlElements&) = delete;

    static MockControlElements& Instance();

    void registerButtonClick(const std::function<void()>& callback);
    void registerLabelClick(const std::function<void()>& callback);
    void registerLineEditInput(const std::function<void(const std::string&)>& callback);
    void registerWindowClick(const std::function<void(int, int)>& callback);

    void runButtonClick(std::size_t index);
    void runLabelClick(std::size_t index);
    void runLineEditInput(std::size_t index, const std::string& input);
    void runWindowClick(std::size_t index, int x, int y);

    std::unique_ptr<RasterImage> getRasterImageFromPrimitives(
            const std::list<std::shared_ptr<Primitive>>& primitives);

private:
    MockControlElements() = default;
    ~MockControlElements() = default;

private:
    std::vector<std::function<void()>> m_buttons;
    std::vector<std::function<void()>> m_labels;
    std::vector<std::function<void(const std::string&)>> m_lineEdits;
    std::vector<std::function<void(int, int)>> m_windows;
};


#endif //ARCHITECTURE_MOCKLINUXCONTROLELEMENTS_H
