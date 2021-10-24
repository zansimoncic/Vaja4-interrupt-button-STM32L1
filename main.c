/* USER CODE BEGIN Glava */
/* *
  ************************************************ ****************************
  * @datoteka: main.c
  * @brief : telo glavnega programa
  ************************************************ ****************************
  * @ pozornost
  *
  * <h2> <center> & copy; Avtorske pravice (c) 2021 STMicroelectronics.
  * Vse pravice pridržane.</center></h2>
  *
  * To programsko komponento licencira ST pod licenco BSD 3-Clause,
  * "Licenca"; Te datoteke ne smete uporabljati razen v skladu z
  * Licenca. Kopijo licence lahko dobite na:
  * opensource.org/licenses/BSD-3-Clause
  *
  ************************************************ ****************************
  */
/* Glava KONCA UPORABNIŠKE KODE */
/* Vključuje ----------------------------------------------- ------------------- */
# vključuje  " main.h "

/* Zasebno vključuje ------------------------------------------------------- ------------ */
/* USER CODE BEGIN Vključuje */

/ * KOD UPORABNIKA KONEC Vključuje */

/* Private typedef ------------------------------------------------------- ------------- */
/* UPORABNIŠKA KODA ZAČNI PTD */

/* UPORABNIŠKA KODA KONEC PTD */

/* Zasebno definiraj ------------------------------------------------------- -------------- */
/ * KODA UPORABNIKA SE ZAČNE PD */
/ * KOD UPORABNIKA KONEC PD */

/* Zasebni makro ------------------------------------------------------- --------------- */
/* UPORABNIŠKA KODA ZAČETEK PM */

/* UPORABNIŠKA KODA KONEC PM */

/* Zasebne spremenljivke ------------------------------------------------------- ----------- */

/* UPORABNIŠKA KODA ZAČNI PV */

/ * KOD UPORABNIKA KONEC PV */

/* Prototipi zasebnih funkcij ----------------------------------------------------- -- */
void  SystemClock_Config ( void );
statična  praznina  MX_GPIO_Init ( void );
/ * KODA UPORABNIKA SE ZAČNE PFP */

/* UPORABNIŠKA KODA KONEC PFP */

/* Koda zasebnega uporabnika ----------------------------------------------------- ------------ */
/* UPORABNIŠKA KODA ZAČNI 0 */

/* UPORABNIŠKA KODA KONEC 0 */

/* *
  * @brief Vstopna točka aplikacije.
  * @retval int
  */
int  main ( void )
{
  / * KODA UPORABNIKA SE ZAČNE 1 */
	GPIO_PinState moja_tipka;

  /* UPORABNIŠKA KODA KONEC 1 */

  /* Konfiguracija MCU-------------------------------------------------------- ---------- */

  /* Ponastavi vse zunanje naprave, inicializira vmesnik Flash in Systick. */
  HAL_Init ();

  /* USER CODE BEGIN Init */

  /* KONEC USER CODE Init */

  /* Konfigurirajte sistemsko uro */
  SystemClock_Config ();

  /* USER CODE BEGIN SysInit */

  / * KODA UPORABNIKA END SysInit */

  /* Inicializira vse konfigurirane zunanje naprave */
  MX_GPIO_Init ();
  / * KODA UPORABNIKA SE ZAČNE 2 */

  /* UPORABNIŠKA KODA KONEC 2 */

  /* Neskončna zanka */
  / * KODA UPORABNIKA SE ZAČNE, medtem ko */
  medtem ko ( 1 )
  {
    /* UPORABNIŠKA KODA SE KONČA DOKAJ */

    /* UPORABNIŠKA KODA ZAČETEK 3 */
	  HAL_GPIO_TogglePin (GPIOC, Modra_LED_Pin);
	  HAL_Zamik ( 500 );
	  moja_tipka = HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0);
	  če (moja_tipka == 1 ){
	    HAL_GPIO_WritePin (GPIOC, Zelena_LED_Pin, GPIO_PIN_SET);
      }
	  drugače {
		  HAL_GPIO_WritePin (GPIOC, Zelena_LED_Pin, GPIO_PIN_RESET);
	  }

  }
  /* UPORABNIŠKA KODA KONEC 3 */
}

/* *
  * @brief konfiguracija sistemske ure
  * @retval Brez
  */
void  SystemClock_Config ( void )
{
  RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
  RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

  /* * Konfigurirajte izhodno napetost glavnega notranjega regulatorja
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG (PWR_REGULATOR_VOLTAGE_SCALE1);
  /* * Inicializira oscilatorje RCC glede na podane parametre
  * v strukturi RCC_OscInitTypeDef.
  */
  RCC_OscInitStruct. OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct. HSIState = RCC_HSI_ON;
  RCC_OscInitStruct. HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct. PLL . PLLState = RCC_PLL_ON;
  RCC_OscInitStruct. PLL . PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct. PLL . PLLMUL = RCC_PLL_MUL6;
  RCC_OscInitStruct. PLL . PLLDIV = RCC_PLL_DIV3;
  če ( HAL_RCC_OscConfig (&RCC_OscInitStruct) != HAL_OK)
  {
    Obdelovalec_napake ();
  }
  /* * Inicializira ure vodil CPU, AHB in APB
  */
  RCC_ClkInitStruct. Vrsta ure = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                              | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct. SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct. AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct. APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct. APB2CLKDivider = RCC_HCLK_DIV1;

  if ( HAL_RCC_ClockConfig (&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Obdelovalec_napake ();
  }
}

/* *
  * @brief funkcija inicializacije GPIO
  * @param Brez
  * @retval Brez
  */
statična  praznina  MX_GPIO_Init ( void )
{
  GPIO_InitTypeDef GPIO_InitStruct = { 0 };

  / * Omogoči uro GPIO Ports */
  __HAL_RCC_GPIOC_CLK_ENABLE ();
  __HAL_RCC_GPIOH_CLK_ENABLE ();
  __HAL_RCC_GPIOA_CLK_ENABLE ();
  __HAL_RCC_GPIOB_CLK_ENABLE ();

  /* Konfiguriraj izhodno raven zatiča GPIO */
  HAL_GPIO_WritePin (GPIOC, Modra_LED_Pin|Zelena_LED_Pin, GPIO_PIN_RESET);

  /* Konfiguriraj GPIO pin: PA0 */
  GPIO_InitStruct. Pin = GPIO_PIN_0;
  GPIO_InitStruct. Način = GPIO_MODE_IT_RISING;
  GPIO_InitStruct. Potegni = GPIO_NOPULL;
  HAL_GPIO_Init (GPIOA, &GPIO_InitStruct);

  /* Konfiguriraj zatiče GPIO: Modra_LED_Pin Zelena_LED_Pin */
  GPIO_InitStruct. Pin = Modra_LED_Pin|Zelena_LED_Pin;
  GPIO_InitStruct. Način = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct. Potegni = GPIO_NOPULL;
  GPIO_InitStruct. Hitrost = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init (GPIOC, &GPIO_InitStruct);

}

/* UPORABNIŠKA KODA ZAČETEK 4 */
void  HAL_GPIO_EXIT_Callback ( uint16_t GPIO_Pin)
{
	UNSED (GPIO_Pin);
	HAL_GPIO_TogglePin (GPIOC, Zelena_LED_Pin);
	za ( uint32_t i= 0 ; i< 10000 ; i++);


}

/* UPORABNIŠKA KODA KONEC 4 */

/* *
  * @brief Ta funkcija se izvede v primeru napake.
  * @retval Brez
  */
void  Error_Handler ( void )
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* Uporabnik lahko doda svojo implementacijo, da poroča o stanju vrnitve napake HAL */
  __disable_irq ();
  medtem ko ( 1 )
  {
  }
  / * KODA UPORABNIKA KONEC Napaka_Handler_Debug */
}

# Ifdef   USE_FULL_ASSERT
/* *
  * @brief Poroča o imenu izvorne datoteke in številki izvorne vrstice
  * kjer je prišlo do napake assert_param.
  * @param datoteka: kazalec na ime izvorne datoteke
  * @param vrstica: assert_param izvorna številka vrstice napake
  * @retval Brez
  */
void  assert_failed ( uint8_t *file, uint32_t vrstica)
{
  / * KODA UPORABNIKA SE ZAČNE 6 */
  /* Uporabnik lahko doda svojo implementacijo, da sporoči ime datoteke in številko vrstice,
     npr: printf("Napačna vrednost parametrov: datoteka %s v vrstici %d\r\n", datoteka, vrstica) */
  /* UPORABNIŠKA KODA KONEC 6 */
}
# endif  /* USE_FULL_ASSERT */

/* *********************** (C) COPYRIGHT STMicroelectronics ***** KONEC DATOTEKE *** */
