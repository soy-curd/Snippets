/// <reference path="../typings/tsd.d.ts"/>

export class MyService {
    constructor() {
    }

    public static addService(a, b) {
        console.log(a);
        return a + b + 10000;
    }
}

// コントローラ定義
// コントローラの役割はスコープのsetup
export class MyController {
    public message: string;
    public hoge: number;
    public $interval: angular.IIntervalService;
    public $location: angular.ILocationService;

    constructor($interval, $location, addService) {
        this.init(addService);
        this.$interval = $interval;
        this.$location = $location;
        console.log(this.$location);

    }

    private init(addService) {
        this.message = "Hello world";
        this.hoge = addService(10, 20);
    }

    public action($event) {
        if (this.message.indexOf("o") > 0) {
            this.message = this.message.slice(0, -1);
        } else {
            this.message = "GooooooooooooooodBye!";
        }
        $event.stopPropagation();
        console.log($event);
    }

    public wait(num) {
        let _num = num;
        this.$interval(() => {
            console.log(_num--);
        }, num);
    }
}

export class ScopeController {
    public $rootScope: angular.IRootScopeService;
    public test: string;

    constructor($rootScope) {
        this.$rootScope = $rootScope;
        this.test = "test1";  // これは$scope
        this.$rootScope["rootTest"] = "rootTest1";
    }
}

export class ScopeController2 {
    public $rootScope: angular.IRootScopeService;
    public test: string;

    constructor($rootScope) {
        this.$rootScope = $rootScope;
        this.test = "test2";  // これは$scope
        this.$rootScope["rootTest"] = "rootTest2";
    }
}
