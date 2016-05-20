/// <reference path="../typings/tsd.d.ts"/>

export interface IMyDirective {
    compile(tElement, tAttrs, tTransclude): any;
}

export class MyDirective implements IMyDirective {
    constructor() {

    }

    public compile(tElement, tAttrs, tTransclude) {
        tElement.text("this is my favorite directive");
        console.log(tElement.text);
        return function link(scope, iElement, iAttrs, controller, iTransclude) {
            scope.$watch("message", (newVal) => tElement.text(newVal))
        }
    }
}

export class ComboBox {
    constructor() {
        console.log("fuga");
        console.log(this);
        return this.createDirective();
    }

    private createDirective(): any {
        return {
            scope: {
                selectedItem: "=",
                allItems: "="
            },
            restrict: "EA",
            template: '<div class="combobox">' + '</div>div',
            link: (scope, iElement)=> {
                return null;
            }
        }

    }
}