import * as React from "react";
import { Field, reduxForm } from "redux-form";

class ContactForm extends React.Component<any, {}> {
  render(): JSX.Element {
    return (
      <form onSubmit={this.props.handleSubmit}>
        <div>
          <label htmlFor="email">証券コードを入力してください</label>
          <Field name="code" component="input" type="number" required/>
        </div>
        <button type="submit">送信</button>
      </form>
    );
  }
}

// Decorate the form component
export default reduxForm({
  form: "contact" // a unique name for this form
})(ContactForm);
