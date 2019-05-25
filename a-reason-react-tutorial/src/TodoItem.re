type item = {
  id: int,
  todoDescription: string,
  completed: bool
};

let lastId = ref(0);

let newItem = (text) => {
  lastId := lastId^ + 1;
  {id: lastId^, todoDescription: text, completed: false}
};

let toString = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("TodoItem");

let make = (~item, ~onToggle, ~onRemove, children) => {
  ...component,
  render: (self) =>
    <div className="item">
      <input
        _type="checkbox"
        checked=(Js.Boolean.to_js_boolean(item.completed))
        onClick=((_evt) => onToggle())
      />
      (toString(item.todoDescription))
      <img
        src="../public/images/remove_icon.svg"
        width="15"
        height="15"
        onClick=((_evt) => onRemove())
      />
    </div>
};