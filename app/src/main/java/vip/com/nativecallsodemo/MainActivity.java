package vip.com.nativecallsodemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    JavaMath javaMath;
    TextView textView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = (TextView) findViewById(R.id.text1);
        javaMath = new JavaMath();
        int i = 20;
        int j = 10;
        textView.setText(javaMath.add(i,j) + "  " + javaMath.sub(i,j) + " "+
        javaMath.mul(i,j) + "  " + javaMath.div(i,j));
    }
}
