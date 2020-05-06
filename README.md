## Vector editor

Self-education task for design patterns practice.

# Requirements

Design a vector graphics editor.

The editor will run on Windows and Ubuntu and will draw its UI using a platform-specific API, so it should be able to draw primitives (straight line, rectangle, circle) on both systems and show the controls native to the system (button, inscription, input field, window ).

The editor must support work with several vector objects at the same time.

Each object can be either a primitive of vector graphics or consist of several primitives, that is, objects must support grouping. In addition, each object must support selection, movement, and resizing. Only primitives should support color change. Objects must support copying.

It should be possible to perform various actions on objects, and it should be possible to cancel the performed actions.

The editor can work in one of 2 modes:
- Creating primitives;
- Editing primitives (changing position, size, color, grouping, deleting).

The response to keyboard and mouse events will depend on the mode. In addition, when switching from one mode to another, you must:
- Change toolbar;
- Display user notification;
- Depending on the mode the editor goes into, you need to change the cursor icon.
... this list of requirements may be expanded in the future

The editor must support image rasterization, in which several filters are applied to the result. Supported Filters:
- Blur;
- Translation in BW;
- Contrast enhancement;
- Radiance;
- Retro.

And should be able to apply any combination of these filters.

As a concrete implementation of the interfaces, you need to use mock classes that will output messages to the log instead of real work.

# Implementation details

1. The `Bridge` design pattern to separate GUI logic 
(control elements, state, transitions between states)
and the `Editor` logic;
2. The `Abstract Factory` design pattern for the ability to obtain a control element
(`Button`, `Label`, `LineEdit`, `Window`) via specific system 
(`LinuxControlsFactory`, `WindowsControlsFactory`);
3. The `Mediator` design pattern for the interaction of control elements with
`GUIMediator`;
4. The `Observer` design pattern for the ability to perform all necessary
actions (change the toolbar, display a notification, change the cursor icon, etc.) 
when a user switches between states (`EventManager`, `Subscriber`);
5. The `State` design pattern for `GUIMediator` 
to limit actions for a specific mode (creation of primitives, editing of primitives) 
(`CreatingEditorState`, `EditingEditorState`);
6. The `Command` design pattern to perform actions on primitives 
with a possibility  of cancellation;
7. The `Composite` design pattern for a possibility of grouping primitives;
8. The `Prototype` design pattern for the ability to copy primitives;
9. The `Bridge` design pattern to separate the ability to draw the primitive
(`LinuxPainter`, `WindowsPainter`) from their management;
10. The `Decorator` design pattern for the ability to apply a filter for an image;
11. The `Singleton` design pattern for the Mock object, 
which registers callbacks for control elements and gives the ability to call the callbacks.
