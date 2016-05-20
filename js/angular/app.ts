/// <reference path="./typings/tsd.d.ts"/>

import * as angular from "angular";
import {MyService, MyController, ScopeController, ScopeController2} from "./controller/myController";

// モジュール定義
// angular.module(name, [requires], [configFn])
// 第二引数がある場合のみモジュールが作成されるため、依存するモジュールがない場合は
// 空配列を渡す。
var appModule = angular.module("app", []);

// サービス定義
appModule.value("addService", MyService);

// コントローラ定義
appModule.controller("MyController", ["$interval", "$location", "addService", MyController]);
appModule.controller("scopeController", ["$rootScope", ScopeController]);
appModule.controller("scopeController2", ["$rootScope", ScopeController2]);
