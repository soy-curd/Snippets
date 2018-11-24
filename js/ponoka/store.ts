import { createStore, applyMiddleware, combineReducers, Action } from "redux";
import thunkMiddleware from "redux-thunk";
import * as prom from "redux-promise";
import { reducer as formReducer } from "redux-form";

export enum ActionTypes {
  tick
}

export interface TickAction extends Action {
  light: boolean;
  ts: Date;
}

export interface State {
  lastUpdate: Date | number;
  light: boolean;
}

export interface States {
  store: State;
  form: any;
}

const storeReducer = (state: State = {lastUpdate: 0, light: false}, action: TickAction): State => {
  switch (action.type) {
    case ActionTypes.tick:
      return {lastUpdate: action.ts, light: !!action.light};
    default:
      return state;
  }
};

const reducerers = combineReducers({ store: storeReducer, form: formReducer });

export const startClock = () => dispatch => {
  return setInterval(() => dispatch({type: ActionTypes.tick, light: true, ts: Date.now()}), 800);
};

export const initStore = (initialState) => {
  return createStore(reducerers, initialState, applyMiddleware(prom, thunkMiddleware));
};
