/// <reference path="../typings/tsd.d.ts"/>

export class MyAppComponent {
    template = `<counter count="0"></counter>`;
    controller:MyAppCtrl
}

export class MyAppCtrl {

}

export class CounterComponent {
    bindings = {
        count: "<"  // データフローの決定
    };
    controller:CounterCtrl;
    template = [
        '<div class="todo">',
        '<input type="text" ng-model="$ctrl.count">',
        '<button type="button" ng-click="$ctrl.dec();">-</button>',
        '<button type="button" ng-click="$ctrl.inc();">+</button>',
        '{{$ctrl.count}}',
        '</div>'
    ].join('');
}

export class CounterCtrl {
    public count: number;

    constructor() {
        this.count = 0;
    }

    public inc() {
        console.log(this.count);
        this.count++;
    }

    public dec() {
        this.count--;
    }

}