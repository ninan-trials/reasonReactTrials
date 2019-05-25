type state = string;

let component = ReasonReact.reducerComponent("Input");

let valueFromEvent = (evt) : string => (
    evt
    |> ReactEventRe.Form.target
    |> ReactDOMRe.domElementToObj
  )##value;
  
let make = (~onSubmit, _) => {
    ...component,
    initialState: () => "",
    reducer: (newText, _text) => ReasonReact.Update(newText),
    render: ({state: text, reduce}) => 
        <input 
        _type="text" 
        value=text
        placeholder= "Add Something New"
        onChange=(reduce((evt) => valueFromEvent(evt)))
        onKeyDown=((evt) =>
            if (ReactEventRe.Keyboard.key(evt) == "Enter") {
                onSubmit(text);
                (reduce(() => ""))()
            }   
        )
         />
};