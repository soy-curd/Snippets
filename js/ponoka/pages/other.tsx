import * as React from "react";
import * as withRedux from "next-redux-wrapper";

import { initStore, startClock, ActionTypes } from "../store";
import Page from "../components/Page";

interface Props {
    url: any;
    isServer: boolean;
    dispatch: Function;
}

class Counter extends React.Component<Props, {}> {
    private timer: number;

    // 初期ロードかルーティング時に読み込まれる
    static async getInitialProps({ store, isServer }): Promise<any> {
        store.dispatch({ type: ActionTypes.tick, light: !isServer, ts: Date.now() });
        return { isServer };
    }

    componentDidMount(): void {
        this.timer = this.props.dispatch(startClock());
    }

    componentWillUnmount(): void {
        clearInterval(this.timer);
    }

    render(): JSX.Element {
        return (
            <Page title="Other Page" linkTo="/"/>
        );
    }
}

export default withRedux(initStore)(Counter);
