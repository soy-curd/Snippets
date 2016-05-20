var angular = require("angular");
var myController_1 = require("./controller/myController");
var appModule = angular.module("app", []);
appModule.value("addService", myController_1.MyService);
appModule.controller("MyController", myController_1.MyController);
//# sourceMappingURL=app.js.map