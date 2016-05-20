/// <reference path="./typings/tsd.d.ts"/>

import * as angular from "angular";
import {MyController, ScopeController, ScopeController2} from "./controller/myController";
import {MyService} from "./services/myService";
import {ComboBox} from "./components/myDirective";
import {MyAppCtrl, GreetingCtrl, CounterCtrl} from "./components/myComponent";

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

appModule.component("myApp", {
    //template: `<greeting name="'World'"></greeting>`,
    template: `<counter count="0"></counter>`,
    controller: MyAppCtrl
});

appModule.component("greeting", {
    bindings: {
        name: "="
    },
    template: `<h1>Hello {{$ctrl.upperName}}!</h1>`,
    controller: GreetingCtrl
});

appModule.component("counter", {
    bindings: {
        count: "<"  // データフローの決定
    },
    controller: CounterCtrl,
    template: [
        '<div class="todo">',
        '<input type="text" ng-model="$ctrl.count">',
        '<button type="button" ng-click="$ctrl.dec();">-</button>',
        '<button type="button" ng-click="$ctrl.inc();">+</button>',
        '{{$ctrl.count}}',
        '</div>'
    ].join('')
});