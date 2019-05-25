
let component = ReasonReact.statelessComponent("App");

let make = (~message, _children) => {
  ...component,
  render: (_self) =>
    <div className="App">
      <div className="App-header">
        <h1> (ReasonReact.stringToElement("Reason Projects")) </h1>
      </div>
    </div>
};
