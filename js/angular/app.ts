/// <reference path="./typings/tsd.d.ts"/>

import * as angular from "angular";
import {MyController, ScopeController, ScopeController2} from "./controller/myController";
import {MyService} from "./services/myService";
import {ComboBox} from "./components/myDirective";
import {MyAppComponent, CounterComponent} from "./components/myComponent";

// モジュール定義
// angular.module(name, [requires], [configFn])
// 第二引数がある場合のみモジュールが作成されるため、依存するモジュールがない場合は
// 空配列を渡す。
var appModule = angular.module("app", []);

// サービス定義
appModule.value("addService", MyService);
appModule.service("myService", ["$http", MyService]);
// コントローラ定義
appModule.controller("MyController", ["$interval", "$location", "addService", "myService", MyController]);
appModule.controller("scopeController", ["$rootScope", ScopeController]);
appModule.controller("scopeController2", ["$rootScope", ScopeController2]);
// ディレクティブ定義
//appModule.directive("myDirective", [MyDirective]);
appModule.directive("comboBox", [() => new ComboBox()]);

// コンポーネント定義
appModule.component("myApp", new MyAppCtrl());
appModule.component("counter", new CounterComponent());