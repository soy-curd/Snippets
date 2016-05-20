/// <reference path="./typings/tsd.d.ts"/>

import * as angular from "angular";
import {MyService, MyController} from "./controller/myController";

var appModule = angular.module("app", []);
appModule.value("addService", MyService);
appModule.controller("MyController", MyController);
