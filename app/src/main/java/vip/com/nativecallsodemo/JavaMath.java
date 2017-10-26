package vip.com.nativecallsodemo;

/**
 * Created by wudeng on 17/10/26.
 */

public class JavaMath {

    static {
        System.loadLibrary("somath");
        System.loadLibrary("mymath");
    }

    public native int add(int i, int j);

    public native int sub(int i, int j);

    public native int mul(int i, int j);

    public native int div(int i, int j);

}
