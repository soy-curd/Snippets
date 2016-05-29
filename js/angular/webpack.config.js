module.exports = {
    entry: './app.js',
    output: {
        filename: './build/bundle.js'
    },
    module: {},
    externals: {
        "angular": "angular"
    },
    resolve: {
        extensions: ['', '.js', '.jsx']
    }
};