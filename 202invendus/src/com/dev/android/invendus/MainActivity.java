package com.dev.android.invendus;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity {

	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		final Button calc = (Button) this.findViewById(R.id.buttonCalc);
		final Button reset = (Button) this.findViewById(R.id.buttonReset);
		final EditText valOne = (EditText) this
				.findViewById(R.id.editTextValOne);
		final EditText valTwo = (EditText) this
				.findViewById(R.id.editTextValTwo);

		calc.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) {
				String aString = valOne.getText().toString();
				String bString = valTwo.getText().toString();
				if ((aString.length() == 0) || (bString.length() == 0))
					Toast.makeText(MainActivity.this, "Please, enter a nember",
							Toast.LENGTH_LONG).show();
				else {
					int a = Integer.parseInt(aString);
					int b = Integer.parseInt(bString);
					Result.affResult(MainActivity.this, a, b);
				}
			}
		});

		reset.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) {
				valOne.setText("");
				valTwo.setText("");
			}
		});

	}
}
