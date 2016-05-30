/// <reference path="../typings/tsd.d.ts"/>

import * as angular from "angular";

class Pane {
    public selected:boolean;
    public title:string;
}

export class MyAppComponent {
    transclude = true;
    template = `
    parent count is {{$ctrl}}{{$ctrl.parentCount}}

    <div class="tabbable">
      <ul class="nav nav-tabs">
        <li ng-repeat="pane in $ctrl.panes" ng-class="{active:pane.selected}">
          <a href="" ng-click="$ctrl.select(pane)">{{pane.title}}</a>
        </li>
      </ul>
      <div class="tab-content" ng-transclude></div>
    </div>

    `;
    controller:MyAppCtrl
}

export class MyAppCtrl {
    parentCount:number = 999;
    panes = [];

    public select(pane:Pane) {
        angular.forEach(this.panes, (pane) => {
            pane["selected"] = false;
        });
        pane.selected = true;
    };

    public addPane(pane:Pane) {
        if (this.panes.length === 0) {
            this.select(pane);
        }
        this.panes.push(pane);

    };
}


export class PaneComponent {
    transclude = true;
    require = {
        tabsCtrl: '^myApp'  // myAppと値を共有
    };
    bindings = {
        title: '@'
    };
    controller = function () {
        this.$onInit = function () {
            console.log(this);
            //this.tabsCtrl.addPane(this);
        };
    };
    template = `

    </br>
    abcde
    <div class="tab-pane" ng-if="{{$ctrl}}" ng-show="$ctrl.selected" ng-transclude>
        {{$ctrl}}
        {{$ctrl.selected}}
    </div>
    `
}


export class CounterComponent {
    bindings = {
        count: "<"  // データフローの決定
    };
    controller = CounterCtrl;
    template = [
        '<div class="todo">',
        '<input type="text" ng-model="$ctrl.count">',
        '<button type="button" ng-click="$ctrl.dec();">-</button>',
        '<button type="button" ng-click="$ctrl.inc();">+</button>',
        'child count is {{$ctrl.count}}',
        '</div>'
    ].join('');
}

export class CounterCtrl {
    public count:number;

    //constructor() {
    //    this.count = 0;
    //}

    public inc() {
        console.log(this.count);
        this.count++;
    }

    public dec() {
        this.count--;
    }

}
