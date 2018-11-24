import * as express from "express";
import * as next from "next";

const dev = process.env.NODE_ENV !== "production";
const app = next({ dev });
const handle = app.getRequestHandler();

console.log("hoge");
app.prepare()
  .then(() => {
    const server = express();

    server.get("/v1/a", (req, res) => {
      return res.json({ a: 1000 });
    });

    server.get("*", (req, res) => {
      return handle(req, res);
    });

    server.listen(3000, (err) => {
      if (err) {
        throw err;
      }
        
      console.log("> Ready on http://localhost:3000");
    });
});
