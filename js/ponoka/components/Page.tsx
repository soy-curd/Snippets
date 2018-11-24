import * as React from "react";
import Link from "next/link";
import { connect } from "react-redux";
import axios from "axios";

import { States } from "../store";
import Clock from "./Clock";
import StockForm from "./StockForm";

export interface PageProps {
  title: string;
  linkTo: string;
}

class Page extends React.Component<States & PageProps, {}> {
  submit (values): void {
    axios.get("/v1/a")
      .then((res) => {
        console.log("axios res", res.data.a);
        console.log(values);
      });
  }
  
  render(): JSX.Element {
    console.log("prop ", this.props);
    return (
      <div>
        <h1>{this.props.title}</h1>
        <StockForm onSubmit={this.submit} />
        <Clock lastUpdate={this.props.store.lastUpdate} light={this.props.store.light}/>
        <nav>
          <Link href={this.props.linkTo}>
            <a>Navigate</a>
          </Link>
        </nav>
      </div>
    );
  }
}

const mapStateToProps = (state) => state;


export default connect<States, {}, PageProps>(mapStateToProps)(Page);
