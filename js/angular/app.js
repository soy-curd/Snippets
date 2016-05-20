
var MyService = function (a, b) {
  console.log(a);
  return a + b;
};

var MyController = function ($scope, addService) {  // 自動で名前解決する
  $scope.message = "Hello world";
  $scope.action = function ($event) {
    if ($scope.message.indexOf("o") > 0) {
      $scope.message = $scope.message.slice(0, -1);
    } else {
      $scope.message = "GooooooooodBye!";
    }
    
    $scope.hoge = addService(10, 20);
    $event.stopPropagation();
    console.log($event);
  };
};
var appModule = angular.module("app", []);
appModule.value("addService", MyService)
appModule.controller("MyController", MyController);
