/// <reference path="../typings/tsd.d.ts"/>

export interface IMyService {
    getResponse(): string;
}

export class MyService implements IMyService {
    public $http: angular.IHttpService;


    constructor($http) {
        this.$http = $http;
    }

    public static addService(a, b) {
        console.log(a);
        return a + b + 10000;
    }

    public getResponse() {
        let _res = null;
        this.$http.get("http://localhost:8082/").success((res) => {
            console.log("ふが", res);
            _res = res;
        });
        return _res;
    }

}

