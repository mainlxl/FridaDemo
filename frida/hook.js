// frida -U -f com.mainli.fridademo -l hook.js --pause
setImmediate(function () {
    Java.perform(function () {
        var MainActivity = Java.use("com.mainli.fridademo.MainActivity");
        console.log("类加载成功");
        console.log("方法:", Object.getOwnPropertyNames(MainActivity).filter(x => x.startsWith('onR')));

        MainActivity.onCreate.implementation = function (savedInstanceState) {
            printStackTrace("MainActivity.onCreate Stack");
            this.onCreate(savedInstanceState);
        };

        var count = 0;
        MainActivity.stringFromJNI.implementation = function () {
            printStackTrace(`${ this.stringFromJNI()} -- stringFromJNI call ${count}`);
            return `Hello from Frida -> Count: ${count++}`;
        };
    });
});




function printStackTrace(prefix = "stack", maxLines = 20, showThread = false) {
    const Log = Java.use("android.util.Log");
    const Throwable = Java.use("java.lang.Throwable");
    const Thread = Java.use("java.lang.Thread");
    let output = "";
    if (showThread) {
        const currentThread = Thread.currentThread();
        output += `[线程: ${currentThread.getName()}]\n`;
    }
    output += `${prefix}:\n`;
    const stackTrace = Log.getStackTraceString(Throwable.$new());
    const lines = stackTrace.split("\n").slice(1);
    const displayLines = maxLines > 0 ? lines.slice(0, maxLines) : lines;
    output += displayLines.map(line => `  ${line}`).join("\n");
    if (maxLines > 0 && lines.length > maxLines) {
        output += `\n  ... (${lines.length - maxLines} more lines)`;
    }
    console.log('------------------------------------------------\n' + output + '\n------------------------------------------------');
}