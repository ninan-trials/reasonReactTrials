let toString = ReasonReact.stringToElement;

type state = {items: list(TodoItem.item)};

type action =
  | AddItem(string)
  | ToggleItem(int)
  | RemoveItem(int);

let component = ReasonReact.reducerComponent("TodoApp");

let make = (children) => {
  ...component,
  initialState: () => {items: []},
  reducer: (action, {items}) =>
    switch action {
    | AddItem(text) => ReasonReact.Update({items: [TodoItem.newItem(text), ...items]})
    | RemoveItem(id) =>
      let items = List.filter((item: TodoItem.item) => item.id !== id, items);
      ReasonReact.Update({items: items})
    | ToggleItem(id) =>
      let items =
        List.map(
          (item: TodoItem.item) => item.id === id ? {...item, completed: ! item.completed} : item,
          items
        );
      ReasonReact.Update({items: items})
    },
  render: ({state: {items}, reduce}) => {
    let numOfItems = List.length(items);
    <div className="app">
      <div className="title">
        (toString("What to do"))
        <Input onSubmit=(reduce((text) => AddItem(text))) />
      </div>
      <div className="items">
        (
          ReasonReact.arrayToElement(
            Array.of_list(
              List.map(
                (item: TodoItem.item) =>
                  <TodoItem
                    key=(string_of_int(item.id))
                    onToggle=(reduce(() => ToggleItem(item.id)))
                    onRemove=(reduce(() => RemoveItem(item.id)))
                    item
                  />,
                items
              )
            )
          )
        )
      </div>
      <div className="footer"> (toString(string_of_int(numOfItems) ++ " items")) </div>
    </div>
  }
};
/*
 Things to try and implement:

 Removing items
 Select all/Unselect all
 Changing background colors and themes for the app.
 Creating tags for each item and filtering based on tags
 Storing the list in a format on disk
 Using storage on disk to create a list
 */