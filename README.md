## Vector editor

Self-education task for design patterns practice.

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
